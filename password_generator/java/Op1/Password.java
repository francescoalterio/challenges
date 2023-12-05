package password_generator.java.Op1;

import java.util.ArrayList;
import java.util.stream.IntStream;
import java.util.Arrays;

public class Password {
    Integer[] lowerLetters = IntStream.rangeClosed(97, 122).boxed().toArray(Integer[]::new);
    ArrayList<Integer> options = new ArrayList<Integer>(Arrays.asList(lowerLetters));
    int length = 8;
    public Password(boolean withCapital, boolean withNumbers, boolean withSymbols) {
        if(withCapital) {
            Integer[] capitalLetters = IntStream.rangeClosed(65, 90).boxed().toArray(Integer[]::new);
            options.addAll(Arrays.asList(capitalLetters));
        }
        if(withNumbers) {
            Integer[] numbers = IntStream.rangeClosed(48, 57).boxed().toArray(Integer[]::new);
            options.addAll(Arrays.asList(numbers));
        }
        if(withSymbols) {
            Integer[] symbols1 = IntStream.rangeClosed(32, 47).boxed().toArray(Integer[]::new);
            Integer[] symbols2 = IntStream.rangeClosed(58, 64).boxed().toArray(Integer[]::new);
            Integer[] symbols3 = IntStream.rangeClosed(91, 96).boxed().toArray(Integer[]::new);
            Integer[] symbols4 = IntStream.rangeClosed(123, 126).boxed().toArray(Integer[]::new);
            options.addAll(Arrays.asList(symbols1));
            options.addAll(Arrays.asList(symbols2));
            options.addAll(Arrays.asList(symbols3));
            options.addAll(Arrays.asList(symbols4));

        }
    }

    public String generate(int length) {
        if(length < 8 || length > 16) {
            throw new Error("The password length must be between 8 and 16 characters.");
        }
        this.length = length;
        return this.createPassword();
    }

    public String generate() {
        return this.createPassword();
    }

    private String createPassword() {
        String password = "";
        for(int i = 1; i <= this.length; i++) {
            int randomIndexCharacter = (int) (Math.random() * this.options.size());
            char character = (char) (int) this.options.get(randomIndexCharacter);
            password += character;
        }
        return password;
    }
}
