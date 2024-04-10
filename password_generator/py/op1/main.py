from Password import Password

password = Password(upper_leters=True, numbers=True, symbols=True)
print(password.generate(16))
myPassword2 = Password();
print(myPassword2.generate());
myPassword3 = Password(upper_leters=False, numbers=False, symbols=True);
print(myPassword3.generate(16));
myPassword3 = Password(upper_leters=True, numbers=False, symbols=True);
print(myPassword3.generate(16));