#a partir de alpine
FROM alpine:3.21

#maj de apk, installe nginx, permet de ne pas nettoyer le cache apres et gerer les sertif tls auto-signé
RUN apk update && apk add --no-cache nginx openssl curl

#creer les dossiers necessaire
RUN mkdir -p /etc/nginx/ssl /var/log/nginx /var/run/nginx /var/www/html && \
    chown -R nginx:nginx /var/log/nginx /var/run/nginx /var/www/html

#lance la cmd openssl req pour creer un certificat auto-signé
#en format X.509, standard pour tls/ssl
#no des, ne chiffre pas la clé privée, donc pas de mdp a chaque demarage
#validité du certificat 365j
#genere une paire clé privée + certificat avec un algo RSA sur 2048 bits
#fichier de sortie pour la clé privée
#fichier de sortie pour le certificat public
#remplit en auto les infos demandées normalement en mode interactif
# C=country, ST=state, L=lacality, O=organization, OU=orga.unit, CN=common name
RUN openssl req -x509 -nodes -days 365 -newkey rsa:2048 \
    -keyout /etc/nginx/ssl/nginx.key \
    -out /etc/nginx/ssl/nginx.crt \
    -subj "/C=FR/ST=IDF/L=Paris/0=42/OU=42/CN=daavril.42.fr"

#je copie ma config dans celle du conteneur
COPY ./conf/nginx.conf /etc/nginx/nginx.conf
#test
# COPY ./index.html /var/www/html/index.html

#creer le dossier où sont les fichiers wp
#change le proprietaire et le groupe du dossier vers l'user nginx
# -R recursif, pour tout le contenu du dossier
# nginx:nginx user et groupe créés avec le package nginx sur alpine
RUN mkdir -p /var/www/html && chown -R nginx:nginx /var/www/html

#et je lance le serveur nginx en precisant
#qu'il ne doit pas passer en arriere-plan
#sinon le conteneur se stop
CMD ["/usr/sbin/nginx", "-g", "daemon off;"]
