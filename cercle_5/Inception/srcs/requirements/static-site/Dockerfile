FROM alpine:3.21

RUN apk update && apk add --no-cache busybox-extras

WORKDIR /var/www/html

COPY ./site/ .

EXPOSE 80

CMD ["httpd" , "-f", "-p", "80", "-h", "/var/www/html"]
