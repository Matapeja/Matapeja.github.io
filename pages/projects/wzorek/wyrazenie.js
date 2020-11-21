function oblicz() {
    var bS, b;
    do {
        bS = prompt('Wprowadź wartość "b" różną od "0" oraz "-4"');
        b = parseFloat(bS);
        console.log('bS = ' + b, ' typ = ' + typeof(bS), '\nb = ' + b, ' typ = ' + typeof(b));
        if (bS == 0 || bS == -4 || isNaN(b)) alert('Wprowadziłeś: ' + bS + '\nWartość "b" musi być liczbą różną od "0" i "-4". Wprowadź ponownie.');
        else if (bS != b) alert('Wprowadziłeś: ' + bS + '\nWartość "b" musi być liczbą różną od "0" i "-4". Być może podczas wprowadzania liczby zamiast "." dziesiętnej użyłeś ",". Wprowadź ponownie.');
    } while (bS == 0 || bS == -4 || isNaN(b) || bS != b);  // Nan - nie jest liczbą ; żeby nie ucinało 
    
}

