FROM alpine:3.19

#intall php + extension wp
RUN apk update && apk add --no-cache \
    php php-fpm php-mysqli php-json php-curl php-xml \
    php-gd php-mbstring php-zip php-session \
    wget tar curl less bash

#install wp
WORKDIR /var/www/html
RUN wget https://wordpress.org/latest.tar.gz \
    && tar -xzf latest.tar.gz --strip-components=1 \
    && rm latest.tar.gz

#copy la config de php-fpm
COPY ./conf/www.conf /etc/php/php-fpm.d/www.conf

COPY ./tools/setup_wp.sh /usr/local/bin/setup_wp.sh
RUN chmod +x /usr/local/bin/setup_wp.sh

# COPY ./tools/create_db.sh /usr/local/bin/create_db.sh
# RUN chmod +x /usr/local/bin/create_db.sh

#creer le user
RUN adduser -S www-data -G www-data

#donne les droits a www-data
RUN chown -R www-data:www-data /var/www/html

EXPOSE 9000

#exec le .sh en precisant de demarrer php-fpm en 1er plan
CMD ["sh", "-c", "setup_wp.sh && php-fpm8 --nodaemonize"]