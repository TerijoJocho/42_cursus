#!/bin/sh

set -e

FTP_USER=${FTP_USER:-ftp_user}
FTP_PASSWORD=$(cat /run/secrets/ftp_password)

#creer un user sans mdp, definie son home et l'interdit de se co avec un shell
#-> user que pour ftp qui pointe vers le site wp
if ! id "$FTP_USER" &>/dev/null 2>&1; then
	adduser -D -h /var/www/html -s /bin/false "$FTP_USER"
fi

#on lit le mdp et on l'injecte dans chpasswd
echo "$FTP_USER:$FTP_PASSWORD" | chpasswd

#permissions pour que ftp_user puisse écrire
chown -R "$FTP_USER:$FTP_USER" /var/www/html
find /var/www/html -type d -exec chmod 755 {} \;
find /var/www/html -type f -exec chmod 644 {} \;

# Créer le répertoire pour vsftpd
mkdir -p /var/run/vsftpd/empty

#on remplace le process shell par vsftpd, il devient le PID 1 du container
exec vsftpd /etc/vsftpd/vsftpd.conf
