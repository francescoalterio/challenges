import random

class Password:
    lower_letters: range = range(97, 122)
    length: int
    character_options: list = [*lower_letters]
    def __init__(self, upper_leters: bool = False, numbers: bool = False, symbols: bool = False):
        if upper_leters:
            self.character_options = [*self.character_options, *range(65, 90)]
        if numbers:
            self.character_options = [*self.character_options, *range(48, 57)]
        if symbols:
            self.character_options = [*self.character_options, *range(32, 47),*range(58, 64),*range(91, 96),*range(123, 126)]
    
    def create_password(self) -> str:
        password: str = ""
        for i in range(0, self.length):
            random_character = random.randrange(start=0, stop=len(self.character_options))
            password = password + chr(self.character_options[random_character])
        return password

    def generate(self, length: int = 8) -> str:
        if length < 8 or length > 16:
            raise Exception("The password length must be between 8 and 16 characters.")
        self.length = length
        return self.create_password()
