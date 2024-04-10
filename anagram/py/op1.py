def anagram(word1:str, word2: str):
    if word1 == word2 or sorted(word1.lower()) != sorted(word2.lower()):
        return False
    return True


# TESTS
print("RESULT:", anagram("AIDE", "idea"), f"| EXPECTED: {True}")
print("RESULT:", anagram("aite", "idea"), f"| EXPECTED: {False}")
print("RESULT:", anagram("earth", "heart"), f"| EXPECTED: {True}")
print("RESULT:", anagram("ape", "pea"), f"| EXPECTED: {True}")
print("RESULT:", anagram("hellooo", "helloo"), f"| EXPECTED: {False}")
print("RESULT:", anagram("hi", "hi"), f"| EXPECTED: {False}")