FROM alpine:3.21

# Installer Node.js et dépendances pour builder
RUN apk add --no-cache nodejs npm git python3 build-base

WORKDIR /app

# Cloner le repo
RUN git clone https://github.com/louislam/uptime-kuma.git .

# Installer toutes les dépendances (y compris dev)
RUN npm install

# Builder le front-end
RUN npm run build

# Optionnel : supprimer les dépendances de dev pour alléger l'image
RUN npm prune --production

# Exposer le port web
EXPOSE 3001

# Volume pour les données persistantes
VOLUME /app/data

# Lancer le serveur
CMD ["node", "server/server.js"]
