import random

def generate_unique_integers(count, lower_bound, upper_bound):
    # Verilen aralıktaki benzersiz sayıları üretir
    if upper_bound - lower_bound + 1 < count:
        raise ValueError("Aralık, istenilen sayı adedini barındıramaz.")
    
    unique_integers = random.sample(range(lower_bound, upper_bound + 1), count)
    return unique_integers

# Kullanım örneği:
unique_numbers = generate_unique_integers(100, 1, 1000)

# Sayıları tek satırda, boşlukla ayırarak yazdırmak için
print(" ".join(map(str, unique_numbers)))
