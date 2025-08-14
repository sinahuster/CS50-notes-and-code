phrase = "You're off to great places"

print("Round 1: ", end="")
for i in range(0, len(phrase), 2):
    print(phrase[i], end="")
print("")

print("Round 2: ", end="")
for i in range(1, len(phrase) - 1):
    print(phrase[i], end="")
print()

print("Round 3: ", end="")
for character in phrase:
    print(character, end="")
print()

print("Round 4: ", end="")
for character in phrase[7:]:
    print(character, end="")
print("")

print("Round 5: ", end="")
for word in phrase.split(" "):
    print(word)
print("")
