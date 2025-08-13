#! /bin/sh

#on recup le mdp de la db
DB_PASSWORD=$(cat /run/secrets/db_password)

#copie le fichier modele officiel wp vers celui la
cp wp-config-sample.php wp-config.php

#remplace ces valeurs par les var d'env
sed -i "s/database_name_here/${MYSQL_DATABASE}/" wp-config.php
sed -i "s/username_here/${MYSQL_USER}/" wp-config.php
sed -i "s/password_here/${DB_PASSWORD}/" wp-config.php
#wp ira chercher la db ici
sed -i "s/localhost/${MYSQL_HOST}/" wp-config.php