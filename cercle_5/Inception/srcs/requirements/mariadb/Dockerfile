FROM alpine:3.21

RUN apk update && apk add --no-cache mariadb mariadb-client

RUN mkdir -p /run/mysqld && \
    mkdir -p /var/lib/mysql && \
    chown -R mysql:mysql /var/lib/mysql /run/mysqld

COPY ./tools/init_db.sh /usr/local/bin/init_db.sh
RUN chmod +x /usr/local/bin/init_db.sh

COPY ./conf/my.cnf /etc/my.cnf

COPY ./tools/init.sql /etc/mysql/init.sql

EXPOSE 3306

CMD ["/bin/sh", "-c", "init_db.sh"]
