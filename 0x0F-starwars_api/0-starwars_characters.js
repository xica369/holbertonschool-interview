#!/usr/bin/node
// prints all characters of a Star Wars movie

const request = require('request');
const url = 'https://swapi-api.hbtn.io/api/films/' + process.argv[2];

function getData (charactersUrl) {
  return new Promise((resolve, reject) => {
    request(charactersUrl, (error, response, body) => {
      if (error) reject(error);
      resolve(JSON.parse(body));
    });
  });
}

async function printCharactersName () {
  const body = await getData(url);
  for (let cont = 0; cont < body.characters.length; cont++) {
    const print = await getData(body.characters[cont]);
    console.log(print.name);
  }
}

printCharactersName();
