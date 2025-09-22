FROM alpine:3.21

RUN apk update && apk add --no-cache vsftpd shadow

COPY ./conf/vsftpd.conf /etc/vsftpd/vsftpd.conf
COPY ./tool/entrypoint.sh /usr/sbin/entrypoint.sh

RUN chmod +x /usr/sbin/entrypoint.sh

EXPOSE 21 30000-30010

ENTRYPOINT ["/usr/sbin/entrypoint.sh"]
