#!/bin/bash

mkdir -p /var/run/php
mkdir -p /var/www/html/adminer
wget "https://www.adminer.org/latest.php" -O /var/www/html/adminer/adminer.php
adduser -S www-data -G www-data
chown -R www-data:www-data /var/www/html/adminer
chmod 755 /var/www/html/adminer/adminer.php

/usr/sbin/php-fpm83 --nodaemonize
