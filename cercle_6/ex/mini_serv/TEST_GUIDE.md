# Guide de test pour mini_serv_2

## 1. Compiler le programme

```bash
gcc -Wall -Wextra -Werror mini_serv_2.c -o mini_serv_2
```

## 2. Lancer le serveur

Dans un terminal, lancez le serveur sur un port (exemple: 8080):

```bash
./mini_serv_2 8080
```

Le serveur attend maintenant les connexions sur `127.0.0.1:8080`.

## 3. Tester avec netcat (nc)

### Test basique : un client

Dans un **nouveau terminal**, connectez-vous au serveur:

```bash
nc 127.0.0.1 8080
```

Vous devriez voir apparaître dans le serveur :

- "server: client 0 just arrived\n"

Dans le terminal nc, tapez un message et appuyez sur Entrée :

```
hello
```

Vous devriez voir dans le serveur (et dans tous les autres clients) :

- "client 0: hello\n"

### Test avec plusieurs clients

Ouvrez **plusieurs terminaux** et connectez-vous avec nc :

**Terminal 2:**

```bash
nc 127.0.0.1 8080
```

**Terminal 3:**

```bash
nc 127.0.0.1 8080
```

Vous devriez voir :

- Dans le serveur : "server: client 1 just arrived\n" puis "server: client 2 just arrived\n"
- Chaque client voit tous les messages d'arrivée

### Test de communication entre clients

1. Dans le terminal nc client 0, tapez : `salut tout le monde`
2. Les clients 1 et 2 devraient voir : `client 0: salut tout le monde\n`
3. Dans le terminal nc client 1, tapez : `bonjour`
4. Les clients 0 et 2 devraient voir : `client 1: bonjour\n`

### Test de messages multi-lignes

Dans un terminal nc, tapez :

```
ligne 1
ligne 2
ligne 3
```

Chaque ligne devrait être envoyée séparément avec le préfixe "client X: ".

### Test de déconnexion

Dans un terminal nc, appuyez sur `Ctrl+C` pour quitter.

Tous les autres clients et le serveur devraient voir :

- "server: client X just left\n"

## 4. Test avec script automatique

Créez un fichier `test.sh` :

```bash
#!/bin/bash

PORT=8080

# Lancer le serveur en arrière-plan
./mini_serv_2 $PORT &
SERVER_PID=$!

sleep 1

# Test 1: connexion simple
echo "Test 1: Connexion..."
echo -e "test message\n" | nc 127.0.0.1 $PORT &
sleep 1

# Test 2: plusieurs clients
echo "Test 2: Multiples clients..."
echo -e "client1\n" | nc 127.0.0.1 $PORT &
echo -e "client2\n" | nc 127.0.0.1 $PORT &
sleep 2

# Nettoyer
kill $SERVER_PID 2>/dev/null
echo "Tests terminés"
```

## 5. Vérifications importantes

✅ **Le serveur démarre sans erreur**
✅ **Les clients reçoivent "server: client X just arrived"**
✅ **Les messages sont préfixés avec "client X: "**
✅ **Tous les clients reçoivent les messages des autres**
✅ **Les déconnexions sont annoncées à tous**
✅ **Les IDs sont incrémentaux (0, 1, 2, ...)**
✅ **Pas de fuites mémoire (utiliser valgrind si disponible)**
✅ **Pas de crash lors de déconnexions multiples**

## 6. Commandes utiles

Vérifier que le port est en écoute :

```bash
lsof -i :8080
```

Tuer un processus sur un port :

```bash
kill -9 $(lsof -t -i:8080)
```

Vérifier les fuites mémoire (si valgrind installé) :

```bash
valgrind --leak-check=full ./mini_serv_2 8080
```
