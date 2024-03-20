'''
n people wish to cross a bridge at night. A group of at most two people may cross at any time, and each group must have a flashlight. Only one flashlight is available among the n people, so some sort of shuttle arrangement must be arranged in order to return the flashlight so that more people may cross.
Each person has a different crossing speed; the speed of a group is determined by the speed of the slower member. Your job is to determine a strategy that gets all n people across the bridge in the minimum time.
'''

peopleCount = int(input())

people = []

for i in range(peopleCount):
    people.append(int(input()))

people.sort()

print("list of people: " + str(people))

def updateSlowest(people):
    slowest = people[0]
    for i in people:
        if i > slowest:
            slowest = i
    return slowest

def updateSecondSlowest(people):
    slowest = updateSlowest(people)
    secondSlowest = people[0]
    for i in people:
        if i > secondSlowest and i < slowest:
            secondSlowest = i
    return secondSlowest

fastest = people[0]
secondFastest = people[1]

people_left = people
totalTime = 0
sequence = []

while len(people_left) > 3:
    slowest = updateSlowest(people_left)
    secondSlowest = updateSecondSlowest(people_left)

    firstMethod = 2 * fastest + slowest + secondSlowest
    secondMethod = 2 * slowest + fastest + secondFastest

    if firstMethod < secondMethod:
        totalTime += firstMethod
        sequence.append([fastest, secondFastest])
        sequence.append([fastest])
        sequence.append([slowest, secondSlowest])
        sequence.append([secondFastest])
    else:
        totalTime += secondMethod
        sequence.append([fastest, slowest])
        sequence.append([fastest])
        sequence.append([fastest, secondFastest])
        sequence.append([fastest])
    
    people_left.remove(slowest)
    people_left.remove(secondSlowest)

if len(people_left) == 3:
    sequence.append([people_left[0], people_left[1]])
    sequence.append([people_left[0]])
    a = [people_left[0], people_left[2]]
    sequence.append(a)
    people_left.clear()



if len(people_left) == 2:
    sequence.append(people_left)
    people_left.clear()


if len(people_left) == 1:
    sequence.append(people_left)
    people_left.clear()

print(totalTime)

# print every element in the list on a new line while also removing the brackets and commas
for i in sequence:
    print(str(i).replace("[", "").replace("]", "").replace(",", ""))








