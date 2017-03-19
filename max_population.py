from random import randint

class Person:
    def __init__(self, bd, dd):
        self.birth = bd
        self.death = dd


def max_population(people):
    population = {}
    for person in people:
        for year in range(person.birth, person.death+1):
            try:
                population[str(year)] += 1
            except KeyError:
                population[str(year)] = 1
    return max(population.values())

def generate_random_population_data(n):
    people = []

    for i in range(n):
        a = randint(1800, 2017)
        b = randint(1800, 2017)
        while(b<a):
            b = randint(1800, 2017)
        people.append(Person(a,b))
    return people


people = generate_random_population_data(2000)

print(max_population(people))
