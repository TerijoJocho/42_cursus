# Notes sur minishell

## Les parties d'un shell
### The parser
Il va "lire" la ligne de commande (par exemple : ls -la), et la stocker les commmandes a executer dans la **command table**.<br/>
### The executor
Il va creer un nouveau process pour chaque commande que le parser a pu obtenir. Il peut aussi creer un **pipe**<br/> entre les commandes, cad A | B le resultat de A est utiliser par B.<br/>
#### Exemple
A | B | C | D > outfile < infile > errfile <br/> 
A donne un resultat-> utilise par B qui donne un resultat -> utiliser par C qui donne un resultat -> utiliser par D -> qui donne un resultat -> ce resultat est dans outfile -> le resultat de A est dans infile -> les stderr de toutes les commandes se retrouvent dans errfile<br/>

maj.1 : (daryl) j'ai fais l'arboresence de notre branch master c'est tout