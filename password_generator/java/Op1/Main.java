package password_generator.java.Op1;

public class Main {
    public static void main(String[] args) {
        Password myPassword = new Password(true, true, true);
        System.out.println(myPassword.generate(16));
        Password myPassword2 = new Password(false, false, false);
        System.out.println(myPassword2.generate());
        Password myPassword3 = new Password(false, false, true);
        System.out.println(myPassword3.generate(16));
    }
}
