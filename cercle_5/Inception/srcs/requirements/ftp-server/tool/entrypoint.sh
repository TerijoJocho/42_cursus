#!/bin/bash
FTP_USER=${FTP_USER:-ftp_user}
FTP_PASSWORD=$(cat /run/secrets/ftp_password)

if ! id "$FTP_USER" &>/dev/null; then
	adduser -D -h /var/www/html -s /bin/false "$FTP_USER"
fi

echo -e "$FTP_PASSWORD\n$FTP_PASSWORD" | chpasswd

exec vsftpd /etc/vsftpd/vsftpd.conf
