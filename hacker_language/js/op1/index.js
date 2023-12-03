import letters from "./letters.js";

function leetEncode(message) {
  const messageSplitted = message.toLowerCase().split("");
  const messageEncoded = messageSplitted.map((letter) => {
    const letterEncodeOptions = letters[letter];
    if (!letterEncodeOptions) return letter;
    const randomOption = Math.floor(Math.random() * letterEncodeOptions.length);
    return letterEncodeOptions[randomOption];
  });
  return messageEncoded.join("");
}

//test
console.log(leetEncode("hello"));
console.log(leetEncode("hello, how are you?"));
