function anagram(firstWord, secondWord) {
  const firstWordToLower = firstWord.toLowerCase();
  const secondWordToLower = secondWord.toLowerCase();

  if (
    firstWordToLower === secondWordToLower ||
    firstWordToLower.length !== secondWordToLower.length
  )
    return false;

  const firstWordSorted = firstWordToLower.split("").sort();
  const secondWordSorted = secondWordToLower.split("").sort();

  for (let i = 0; i < firstWordSorted.length; i++) {
    if (firstWordSorted[i] !== secondWordSorted[i]) return false;
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
