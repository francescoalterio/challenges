function anagram(firstWord, secondWord) {
  const firstWordToLower = firstWord.toLowerCase();
  const secondWordToLower = secondWord.toLowerCase();
  if (
    firstWordToLower === secondWordToLower ||
    firstWordToLower.length !== secondWordToLower.length
  )
    return false;

  const first = {};
  const second = {};
  for (let i = 0; i < firstWordToLower.length; i++) {
    if (first[firstWordToLower[i]]) first[firstWordToLower[i]]++;
    else first[firstWordToLower[i]] = 1;
    if (second[secondWordToLower[i]]) second[secondWordToLower[i]]++;
    else second[secondWordToLower[i]] = 1;
  }

  for (const prop in first) {
    if (!second[prop] && second[prop] !== first[prop]) return false;
  }

  return true;
}

//TEST

console.log({
  firstWord: "aide",
  secondWord: "idea",
  expect: true,
  result: anagram("aide", "idea"),
});

console.log({
  firstWord: "aite",
  secondWord: "idea",
  expect: false,
  result: anagram("aite", "idea"),
});

console.log({
  firstWord: "earth",
  secondWord: "heart",
  expect: true,
  result: anagram("earth", "heart"),
});

console.log({
  firstWord: "ape",
  secondWord: "pea",
  expect: true,
  result: anagram("ape", "pea"),
});

console.log({
  firstWord: "hellooo",
  secondWord: "helloo",
  expect: false,
  result: anagram("hellooo", "helloo"),
});

console.log({
  firstWord: "hi",
  secondWord: "hi",
  expect: false,
  result: anagram("hi", "hi"),
});
