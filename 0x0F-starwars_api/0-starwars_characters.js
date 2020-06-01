#!/usr/bin/node
// prints all characters of a Star Wars movie

const request = require('request');
const url = 'https://swapi-api.hbtn.io/api/films/' + process.argv[2];

function get_data (characters_url) {
  return new Promise((resolve, reject) => {
    request(characters_url, (error, response, body) => {
      if (error) reject(error);
        resolve(JSON.parse(body));
    });
  });
}

async function print_characters_name () {
  let body = await get_data(url);
  for (let cont = 0; cont < body.characters.length; cont++) {
    print = await get_data(body.characters[cont]);
    console.log(print.name);
  }
}

print_characters_name()
