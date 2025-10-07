FROM alpine:3.21

#intall php + extension wp
RUN apk update && apk add --no-cache \
    php php-fpm php-mysqli php-json php-curl php-xml \
    php-gd php-mbstring php-zip php-session  php-phar\
    php-tokenizer php-redis php83-ctype wget tar curl less

#install wp
WORKDIR /var/www/html
RUN wget https://wordpress.org/latest.tar.gz \
    && tar -xzf latest.tar.gz --strip-components=1 \
    && rm latest.tar.gz

#install wp-cli
RUN curl -O https://raw.githubusercontent.com/wp-cli/builds/gh-pages/phar/wp-cli.phar \
    && chmod +x wp-cli.phar \
    && mv wp-cli.phar /usr/local/bin/wp

#install client mysql pour .sh
RUN apk add --no-cache mariadb-client

#copy la config de php-fpm
RUN rm -rf /etc/php82/php-fpm.d/*.conf
RUN apk add --no-cache dos2unix
COPY ./conf/www.conf /etc/php83/php-fpm.d/www.conf
RUN dos2unix /etc/php83/php-fpm.d/www.conf

# COPY ./tools/setup_wp.sh /usr/local/bin/setup_wp.sh
# RUN chmod +x /usr/local/bin/setup_wp.sh

#copie de wp si le volume n'existe pas
COPY ./tools/init_wp.sh /usr/local/bin/init_wp.sh
RUN chmod +x /usr/local/bin/init_wp.sh

#creer le user
RUN adduser -S www-data -G www-data

#donne les droits a www-data
RUN chown -R www-data:www-data /var/www/html

EXPOSE 9000

#exec le .sh en precisant de demarrer php-fpm en 1er plan
CMD ["sh", "-c", "init_wp.sh && /usr/sbin/php-fpm83 --nodaemonize"]
