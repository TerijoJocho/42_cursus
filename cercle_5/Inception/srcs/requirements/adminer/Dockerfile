FROM alpine:3.21

# #on installe php + extensions necessaires car adminer est un script php
# RUN apk update && apk add --no-cache \
# 	php php-fpm php-mysqli php-session \
# 	php-json curl wget

# #repertoire de travail
# WORKDIR /var/www/html

# #on telecharge adminer
# RUN wget "https://www.adminer.org/latest.php" -O index.php

# #on prend les configs, comme pour wp
# RUN mkdir -p /run/php
# COPY ./conf/www.conf /etc/php83/php-fpm.d/www.conf

# #creer le user www-data
# RUN adduser -S www-data -G www-data && \
# 	chown -R www-data:www-data /var/www/html

# EXPOSE 9000

#on lance
# CMD ["/usr/sbin/php-fpm83", "--nodaemonize"]


RUN apk update && apk add --no-cache \
	php php-fpm php-mysqli php-session \
	php-json curl wget

COPY ./conf/www.conf /etc/php83/php-fpm.d/www.conf

COPY ./tools/entrypoint.sh /usr/sbin
RUN chmod 755 /usr/sbin/entrypoint.sh

ENTRYPOINT [ "ash", "/usr/sbin/entrypoint.sh" ]

