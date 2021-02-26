class Kwadrat {
    constructor(shape = 1, kanwa, x = 0, y = 0, bok = 40, fill = false, rys = false) {
        if (kanwa == undefined) {
            kanwa = document.createElement("canvas")
            document.body.appendChild(kanwa)
            let kanwaWidth = (window.innerWidth || document.documentElement.clientWidth || document.body.clientWidth) * 0.7
            kanwaWidth = kanwaWidth - (kanwaWidth%10) //zmniejszenie do podzielnej przez 10
            let kanwaHeight = (window.innerHeight || document.documentElement.clientHeight || document.body.clientHeight) * 0.9
            kanwaHeight = kanwaHeight - (kanwaHeight%10)
            kanwa.width = kanwaWidth
            kanwa.height = kanwaHeight
        }
        this.x = x
        this.y = y
        this.bok = bok
        this.kanwa = kanwa
        this.kontekst_kanwy = this.kanwa.getContext('2d')
        this.shape = shape
        this.fill = fill
        this.rys = rys
        this.rysuj(this.shape)
    }

    rysuj(shape) {
        if (!this.rys) this.czysc()
        switch(shape){
            case 1: this.kontekst_kanwy.beginPath() //kwadrat
                    this.kontekst_kanwy.rect (this.x, this.y, this.bok, this.bok)
                    if (this.fill) this.kontekst_kanwy.fill()
                    this.kontekst_kanwy.stroke()
                    break
            case 2: this.kontekst_kanwy.beginPath() //okrąg
                    this.kontekst_kanwy.arc (this.x + this.bok/2, this.y + this.bok/2, this.bok/2, 0, 2*Math.PI)
                    if (this.fill) this.kontekst_kanwy.fill()
                    this.kontekst_kanwy.stroke()
                    break
            case 3: this.kontekst_kanwy.beginPath() //trójkąt prostokątny
                    this.kontekst_kanwy.moveTo(this.x, this.y + this.bok)
                    this.kontekst_kanwy.lineTo(this.x + this.bok, this.y)
                    this.kontekst_kanwy.lineTo(this.x + this.bok, this.y + this.bok)
                    this.kontekst_kanwy.lineTo(this.x, this.y + this.bok)
                    if (this.fill) this.kontekst_kanwy.fill()
                    this.kontekst_kanwy.stroke()
                    break
            case 4: this.kontekst_kanwy.beginPath() //inicjały
                    this.kontekst_kanwy.arc(this.x+this.bok/2, this.y+this.bok/2, this.bok/2, 0.4 * Math.PI, 1.6 * Math.PI);
                    this.kontekst_kanwy.moveTo(this.x + this.bok*0.65, this.y + this.bok*0.98);
                    this.kontekst_kanwy.lineTo(this.x + this.bok*0.65, this.y + this.bok*0.7);
                    this.kontekst_kanwy.moveTo(this.x + this.bok*0.9, this.y + this.bok*0.7);
                    this.kontekst_kanwy.lineTo(this.x + this.bok*0.4, this.y + this.bok*0.7);
                    this.kontekst_kanwy.moveTo(this.x + this.bok*0.5, this.y + this.bok*0.7)
                    this.kontekst_kanwy.lineTo(this.x + this.bok*0.5, this.y + this.bok*0.1);
                    this.kontekst_kanwy.lineTo(this.x + this.bok*0.8, this.y + this.bok*0.7);
                    this.kontekst_kanwy.lineTo(this.x + this.bok*0.8, this.y + this.bok*0.1);
                    this.kontekst_kanwy.stroke()
                    break  
            case 5: this.kontekst_kanwy.beginPath() //romb
                    this.kontekst_kanwy.moveTo(this.x, this.y + this.bok/2)
                    this.kontekst_kanwy.lineTo(this.x + this.bok/2, this.y)
                    this.kontekst_kanwy.lineTo(this.x + this.bok, this.y + this.bok/2)
                    this.kontekst_kanwy.lineTo(this.x + this.bok/2, this.y + this.bok)
                    this.kontekst_kanwy.lineTo(this.x, this.y + this.bok/2)
                    if (this.fill) this.kontekst_kanwy.fill()
                    this.kontekst_kanwy.stroke()
                    break  
            case 6: this.kontekst_kanwy.beginPath() //trójkąt
                    this.kontekst_kanwy.moveTo(this.x, this.y + this.bok)
                    this.kontekst_kanwy.lineTo(this.x + this.bok/2, this.y)
                    this.kontekst_kanwy.lineTo(this.x + this.bok, this.y + this.bok)
                    this.kontekst_kanwy.lineTo(this.x, this.y + this.bok)
                    if (this.fill) this.kontekst_kanwy.fill()
                    this.kontekst_kanwy.stroke()
                    break
        }
    }

    czysc() {
        this.kontekst_kanwy.clearRect (0,0,this.kanwa.width,this.kanwa.height)
    }

    przesun(deltaX, deltaY) {
        if (!this.rys) this.czysc()
        this.x = this.x + deltaX
        this.y = this.y + deltaY
        this.rysuj(this.shape)
    }

    skaluj(s) {
        this.czysc()
        if (s == 1 && this.x > 1 && this.y > 1 && this.x < this.kanwa.width - this.bok && this.y < this.kanwa.height - this.bok) { //warunki, żeby podczas skalowania nie wychodzić poza canvas
            this.bok += 10
            this.x -= 5 
            this.y -= 5
        } else if (s == -1 && this.bok > 20) { // uwarunkowanie najmniejszego poziomu skalowania, żeby obiekt sobie nie zniknął
            this.bok -= 10
            this.x += 5
            this.y += 5
        }
        this.rysuj(this.shape)
    }

    zmienKolorStroke(hex) {
        this.czysc()
        this.kontekst_kanwy.strokeStyle = hex
        this.rysuj(this.shape)
    }

    zmienKolorFill(hex) {
        this.czysc()
        this.kontekst_kanwy.fillStyle = hex
        this.rysuj(this.shape)
    }
}

let KwadratBzzz = new Kwadrat ()
let delta = 10

document.addEventListener("keydown", klawisze)
document.getElementById("btn").addEventListener("click", showKeys) 


function klawisze(event) {
    switch (event.keyCode) {
        case 37: if (KwadratBzzz.x > 0) KwadratBzzz.przesun(-delta,0) // w lewo
                break
        case 38: if (KwadratBzzz.y > 0) KwadratBzzz.przesun(0, -delta) // w górę
                break
        case 39: if (KwadratBzzz.x < KwadratBzzz.kanwa.width - KwadratBzzz.bok) KwadratBzzz.przesun(delta,0) // w prawo
                break
        case 40: if (KwadratBzzz.y < KwadratBzzz.kanwa.height - KwadratBzzz.bok) KwadratBzzz.przesun(0, delta) // w dół
                break
        case 49: KwadratBzzz.shape = 1 //kwadrat
                 KwadratBzzz.rysuj(KwadratBzzz.shape)
                break
        case 50: KwadratBzzz.shape = 2 //okrąg
                 KwadratBzzz.rysuj(KwadratBzzz.shape)
                break
        case 51: KwadratBzzz.shape = 3 //trójkąt prostokąny
                 KwadratBzzz.rysuj(KwadratBzzz.shape)
                break
        case 52: KwadratBzzz.shape = 4 //inicjały
                 KwadratBzzz.rysuj(KwadratBzzz.shape)
                break
        case 53: KwadratBzzz.shape = 5 //romb
                 KwadratBzzz.rysuj(KwadratBzzz.shape)
                break
        case 54: KwadratBzzz.shape = 6 //trójkąt
                 KwadratBzzz.rysuj(KwadratBzzz.shape)
                break
        case 70: if (KwadratBzzz.fill == false) KwadratBzzz.fill = true // wypełnienie obiektu
                 else KwadratBzzz.fill = false
                 KwadratBzzz.rysuj(KwadratBzzz.shape)
               break
        case 82: if (KwadratBzzz.rys == false) KwadratBzzz.rys = true // "rysowanie" obiektem
                 else KwadratBzzz.rys = false
                 break
        case 187: KwadratBzzz.skaluj(1) //powiększanie
                break
        case 189: KwadratBzzz.skaluj(-1) //pomniejszanie
                break
    }
}

function showKeys(){ // ukrywanie/pokazywanie klawiszologii
    var tekst = document.getElementById("tekst")
    if (tekst.style.display === "none") tekst.style.display = "block"
    else tekst.style.display = "none"
}

document.getElementById("stroke-color").addEventListener("input", function() { // pobieranie koloru 
    KwadratBzzz.zmienKolorStroke(document.getElementById("stroke-color").value)});

document.getElementById("fill-color").addEventListener("input", function() { // pobieranie koloru 
    KwadratBzzz.zmienKolorFill(document.getElementById("fill-color").value)});