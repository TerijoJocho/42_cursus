// let input = prompt("Tape un mot: ");

// if (input === "Bonjour")
//     console.log("GG");
// else
//     console.log("Bouuh")

// console.log("À quel chiffre je pense?");
// input = prompt("Devine: ");
// const   chiffre = 5;
// switch (input) {
//     case String(chiffre):
//         console.log("Bravo");
//         break;
//     case "2":
//         console.log("Nul");
//     default:
//         break;
// }

//exo sur les if/else
// const   listeDeMots = ["Cachalot", "Pétunia", "Serviette"];
// let     score = 0;

// while (score !== listeDeMots.length)
// {
//     let mot = prompt("Devinez les trois mots: ");
//     if (mot === listeDeMots.at(score))
//     {
//         score += 1;
//         console.log(`Score: ${score}`);
//     }
//     else
//         console.log("T'es nul");
// }

//exo sur le boucles
// const   listeDeMots = ["Cachalot", "Pétunia", "Serviette"];
// let     score = 0;
// for (let i = 0; i < listeDeMots.length; i++)
// {
//     let input = prompt(`Tapez le mot ${listeDeMots[i]}: `);
//     if (input === listeDeMots[i])
//         score++;
// }
// console.log(`Votre score est de ${score}`);

//exo 2 sur le boucles
// const   listeDeMots = ["Cachalot", "Pétunia", "Serviette"];
// const   listeDePhrases = ["Pas de panique !", "La vie, l’univers et le reste", "Merci pour le poisson"];
// let     score = 0;

// let input = prompt("Quel niveau voulez-vous [mots, phrases] ?");
// while (input !== "mots" && input !== "phrases")
//     input = prompt("Quel niveau voulez-vous [mots, phrases] ?");

// switch (input)
// {
//     case "mots":
//         for (let i = 0; i < listeDeMots.length; i++)
//         {
//             let input = prompt(`Tapez le mot: ${listeDeMots[i]} `);
//             if (input === listeDeMots[i])
//                 score++;
//         }
//         console.log(`Votre score est de ${score}` + " sur " + listeDeMots.length);
//         break;
//     case "phrases":
//         for (let i = 0; i < listeDePhrases.length; i++)
//         {
//             let input = prompt(`Tapez la phrase: ${listeDePhrases[i]} `);
//             if (input === listeDePhrases[i])
//                 score++;
//         }
//         console.log(`Votre score est de ${score}` + " sur " + listeDePhrases.length);
//         break;
// }

//exo sur les fonctions
function returnScore(score, nbDeQuestions)
{
    let str = "Votre score est de " + score + " sur " + nbDeQuestions;
    return str; 
}

function    choixDuNiveau()
{
    let input = prompt("Quel niveau voulez-vous [mots, phrases] ?");
    while (input !== "mots" && input !== "phrases")
        input = prompt("Quel niveau voulez-vous [mots, phrases] ?");
    return input;
}

function    gameLoop(tab)
{
    let score = 0;
    for (let i = 0; i < tab.length; i++)
    {
        let input = prompt(`Tapez : ${tab[i]}`);
        if (input === tab[i])
            score++;
    }
    return score;
}

function    game()
{
    let niveau = choixDuNiveau();
    let resulta = 0;
    let total = 0;

    if (niveau === "mots")
    {
        resulta = gameLoop(listeDeMots);
        total = listeDeMots.length;
    }
    else
    {
        resulta = gameLoop(listeDePhrases);
        total = listeDePhrases.length;
    }
        
    let str = returnScore(resulta, total);
    console.log(str);
}