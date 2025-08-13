#!/bin/sh

#on recup les secrets et les stock dans des var
MYSQL_ROOT_PASSWORD=$(cat /run/secrets/db_root_password)
MYSQL_USER_PASSWORD=$(cat /run/secrets/db_password)

#init la db
#si le dossier n'existe pas => on a jamais eu de db
if [ ! -d "/var/lib/mysql/mysql" ]; then
    echo "Initialisation de MariaDB..."
    #install la strut minimal, les fichiers appartiendront a mysql et supp la sortie pour ne pas avoir de logs
    mariadb-install-db --user=mysql --datadir=/var/lib/mysql > /dev/null

    #init le mdp de root
    mysqld --user=mysql --bootstrap <<-EOSQL
        ALTER USER 'root'@'localhost' IDENTIFIED BY '${MYSQL_ROOT_PASSWORD}';
        CREATE DATABASE IF NOT EXISTS ${MYSQL_DATABASE};
        CREATE USER IF NOT EXISTS '${MYSQL_USER}'@'%' IDENTIFIED BY '${MYSQL_USER_PASSWORD}';
        GRANT ALL PRIVILEGES ON ${MYSQL_DATABASE}.* TO '${MYSQL_USER}'@'%';
        FLUSH PRIVILEGES;
EOSQL
else
    echo "Base déjà initialisée, lancement."
fi

exec mysqld --user=mysql --console