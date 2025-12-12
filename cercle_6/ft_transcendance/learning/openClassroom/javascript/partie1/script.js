/*LES VARIABLES*/
let totalLivres = 500;
totalLivres += 50;
totalLivres -= 10;
totalLivres += 5;
console.log(totalLivres);

let total = String(totalLivres);
let affichageTotalLivres = "Notre bibliothèque possède ";
affichageTotalLivres += total;
affichageTotalLivres += " livres";

// console.log(affichageTotalLivres);

/*LES OBJETS*/
let maCollectionDeFilms = ["Pulp Fiction","Jurassic Park", "Titanic"];
                           
maCollectionDeFilms.push("Retour vers le futur");
console.log(maCollectionDeFilms);

maCollectionDeFilms.push("Batman")
console.log(maCollectionDeFilms);

const elementRecherché = "Batman";

const ticket = {
    nomFilm : maCollectionDeFilms.find(value => value === elementRecherché),
    prix : 5,
    numeroSalle : 23
}

let nom = "Daryl";

console.log(`Bonjour ${nom}, votre film ${ticket.nomFilm} est en salle ${ticket.numeroSalle}`);

/*LES TABLEAUX ET COPIES*/
// Copie par valeur
let variableSimple1 = 25
let variableSimple2 = variableSimple1
variableSimple2 = 30
console.log("variableSimple1", variableSimple1)
console.log("variableSimple2", variableSimple2)
// Copie par référence
//tab declaré en const comme ca leur endroit en memoire reste const et pas leur contenu
const variableComplexe1 = ['pomme', 'cerise']
const variableComplexe2 = variableComplexe1
const variableComplexe3 = [...variableComplexe1];
variableComplexe2.push('poire')
console.log('variableComplexe1', variableComplexe1)
console.log('variableComplexe2', variableComplexe2)
console.log('variableComplexe3', variableComplexe3)
//exo
const   playlist = ["music1", "music2", "music3"];
console.log(playlist);
let     totalMorceaux = playlist.length;
console.log(totalMorceaux);
playlist.push("music4");
playlist.push("music5");
console.log(playlist);
playlist.pop();
console.log(playlist);
