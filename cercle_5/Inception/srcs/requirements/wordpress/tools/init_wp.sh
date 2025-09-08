#! /bin/sh

MYSQL_USER_PASSWORD=$(cat /run/secrets/db_password)
WP_ADMIN_PASSWORD=$(cat /run/secrets/wp_admin_password)
WP_USER_PASSWORD=$(cat /run/secrets/wp_user_password)

MYSQL_DATABASE=${MYSQL_DATABASE:-wp_db}
MYSQL_USER=${MYSQL_USER:-wp_user}
DOMAIN_NAME=${DOMAIN_NAME:-daavril.42.fr}

WP_ADMIN_USER=${WP_ADMIN_USER:-daavril}
WP_ADMIN_EMAIL=${WP_ADMIN_EMAIL:-daril.avril@gmail.com}

WP_USER_NAME=${WP_USER_NAME:-test_user}
WP_USER_EMAIL=${WP_USER_EMAIL:-test@example.com}

echo "Fixing permissions on /var/www/html..."
chown -R www-data:www-data /var/www/html

if [ ! -f wp-settings.php ]; then
	echo "Telechargement de WordPress..."
	php -d memory_limit=256M /usr/local/bin/wp core download --allow-root
fi

until mysql -h mariadb -u"$MYSQL_USER" -p"$MYSQL_USER_PASSWORD" -e "SELECT 1" 2>/dev/null; do
    echo "Waiting for MariaDB..."
    sleep 2
done

if ! wp core is-installed --allow-root; then
    echo "Configuration en cours..."

    wp config create --allow-root \
        --dbname=$MYSQL_DATABASE \
        --dbuser=$MYSQL_USER \
        --dbpass=$MYSQL_USER_PASSWORD \
        --dbhost=mariadb:3306 \
		--path="/var/www/html" \
        --skip-check


    wp core install --allow-root \
        --url=$DOMAIN_NAME \
        --title="wordpress" \
        --admin_user=$WP_ADMIN_USER \
        --admin_password=$WP_ADMIN_PASSWORD \
        --admin_email=$WP_ADMIN_EMAIL

	wp user create "$WP_USER_NAME" "$WP_USER_EMAIL" \
		--role=author \
		--user_pass=$WP_USER_PASSWORD \
		--allow-root

else
    echo "WordPress déjà installé."
fi
