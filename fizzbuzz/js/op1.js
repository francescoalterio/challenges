(function fizzbuzz(index, limit) {
  if (index > limit) return;
  if (index % 15 === 0) console.log("FizzBuzz");
  else if (index % 3 === 0) console.log("Fizz");
  else if (index % 5 === 0) console.log("Buzz");
  else console.log(index);
  return fizzbuzz(index + 1, limit);
})(1, 100);
