---
title: Software design document
author:
- "Nathan Kolpa"
- "Luke Rieff"
toc: true
lang: "nl"
titlepage: true
titlepage-rule-color: "360049"
titlepage-background: "backgrounds/background1.pdf"
---

# Introductie

Het RedCars-systeem vertegenwoordigt een paradigmaverschuiving in de manier waarop RentIt haar klanten benadert. In plaats van klanten naar een centrale locatie te laten komen, brengt RedCars de auto's naar waar de klanten zijn. Dit verhoogt het gemak voor de klant en maximaliseert de beschikbaarheid van voertuigen. De applicatie is bedoeld om alle aspecten van deze service te beheren, van registratie tot betaling.

## Doel van dit document

Dit Software Design Document (SDD) is niet alleen een technische handleiding, maar ook een strategisch instrument dat helpt bij het waarborgen van de projectdoelstellingen en -kwaliteit. Het biedt een gedetailleerd overzicht van hoe elk aspect van het RedCars-systeem functioneert, van architectuur tot gegevensstroom en interacties.

## Definities, acroniemen en afkortingen

- **UI**: User Interface, de ruimte waar interacties tussen mensen en machines plaatsvinden.
- **API**: Application Programming Interface, stelt applicaties in staat om met elkaar te communiceren.
- **CRUD**: Create, Read, Update, Delete - basisfuncties van persistente opslag.
- **RPC**: Remote procedure call

# Architectural Overview

Het RedCars-systeem is ontworpen met schaalbaarheid, efficiëntie en gebruikersgemak in gedachten. De frontend biedt een intuïtieve gebruikerservaring, terwijl de backend is geoptimaliseerd voor snelle gegevensverwerking en -opslag. Externe integraties, zoals betalingsgateways, zijn naadloos verweven om een soepele gebruikerservaring te garanderen.

# Detailed Design Description

## Deployment Diagram 

In onze deployment wordt er gebruik gemaakt van een monolithic server.
Deze server praat met behulp van het HTTP protocol met de mobiele app.
Zowel de stations als de voertuigen praten over een RPC protocol. Als
laatst communiceert de hoofd server via TCP met een database server.

![](./diagrams/dep_dia.png)

## Design Sub-System voor de Server

Dit subsysteem is de kern van de applicatie. Het beheert alle functies met betrekking tot het reserveren van voertuigen: beschikbaarheid controleren, een reservering maken, wijzigen of annuleren, en prijsberekeningen.

## Component diagram

### Algemene black-box view

![](./diagrams/black_box_view_cd.png)

### Controllers white-box view

![](./diagrams/controllers_white_box_view_cd.png)

### Delivery white-box view

![](./diagrams/delivery_white_box_view_cd.png)

### Mail white-box view

![](./diagrams/mail_white_box_view_cd.png)

### Payment white-box view

![](./diagrams/payment_white_box_view_cd.png)

### Repo white box view

![](./diagrams/repo_white_box_view_cd.png)

### View hite box view

![](./diagrams/view_white_box_view_cd.png)

## Design Class Diagram

![](./diagrams/class_diagram.png)

Voor database operaties hebben wij gekozen voor het "unit-of-work" patroon.
Dit maakt het abstraheren van een database mogelijk.
Daarnaast maakt dit patroon het implementeren van een beheer omgeving een stuk makkelijker, omdat we de basis crud operaties kunnen specificeren via een interface die we CrudRepository noemen.

We maken voor externe systeem acties zoals email, betalingen, pasjes bestellen etc.. gebruik van interfaces.
Het moet ook mogelijk zijn om een mock implementatie kunnen vervangen met een echte werkende implementatie.
Dit probleem lossen we om via het dependency injection principe.

Voor het maken van onze domein modellen hebben we ook nog wat extra "fine-grain" klassen toegevoegd.
Dit hebben we gedaan op basis van attributen in onze andere klassen die vaak bij elkaar staan zoals longitude/latitude, tijd/tijdsduur.
Ook variabelen met eenheden hebben hun eigen klassen gekregen, zoals Distance.
Dit voorkomt dat we rekening moeten houden met het anders afhandelen van kilometers, meters, etc...

En om extra correct te zijn om hoe we omgaan met geld, houd de Money class de huidige tijd bij tijdens het aanmaken.
Op deze manier kunnen we voor inflatie compenseren.
Ook gebruiken we geen floats, maar integers van centen zodat we niet tegen float precision problemen aanlopen.


## Sequence Diagrams

Deze diagrammen zouden de interactie tussen de verschillende systeemcomponenten illustreren, zoals hoe een klant een auto reserveert of hoe betalingsinformatie wordt verwerkt.

### Registreren
Het diagram visualiseert het proces waarbij een nieuwe gebruiker zich registreert op het platform. Dit omvat het invoeren van persoonlijke gegevens, het versturen van een bevestigingsmail en het voltooien van de registratie.

![](./diagrams/register_sequence_diagram.png)

### Make reservation
Hier wordt getoond hoe een klant een auto reserveert. Van het selecteren van een beschikbare auto en tijdslot tot het bevestigen van de reservering.

![](./diagrams/make_reservation_sequence_diagram.png)

### Check out
Dit diagram toont hoe een klant uitcheckt nadat hij/zij de gereserveerde auto heeft opgehaald.

![](./diagrams/check_out_sequence_diagram.png)

### Check in
De procedure waarbij een klant incheckt en de auto terugbrengt naar de locatie wordt hier geïllustreerd.

![](./diagrams/check_in_sequence_diagram.png)

## Activity and State Diagrams

Deze diagrammen beschrijven de verschillende stadia en activiteiten die plaatsvinden tijdens specifieke processen in het systeem.

### Abonnement afsluiten
Dit diagram toont de stappen die een klant doorloopt om een abonnement af te sluiten bij RedCars.

![](./diagrams/abonnement_afsluiten_ac.png)

### Activeren automatisch incasso
Het proces waarbij een klant zijn/haar bankrekeningnummer verstrekt en toestemming geeft voor automatische incasso wordt hier beschreven.

![](./diagrams/activeren_automatisch_incasso_ac.png)

### Email verifieren
De stappen die nodig zijn om een e-mailadres te verifiëren na registratie worden hier getoond.

![](./diagrams/email_verifiren_ac.png)

### Factureren
Dit diagram laat zien hoe het factureringsproces verloopt na gebruik van een auto.

![](./diagrams/factureren_ac.png)

### Gegevens van klant aanpassing
Hier wordt het proces beschreven waarbij een klant zijn/haar persoonlijke gegevens kan wijzigen.

![](./diagrams/gegevens_van_klant_aanpassen.png)

### GPS Tracking
Dit diagram toont het proces van hoe het systeem een auto volgt met behulp van GPS-tracking.

![](./diagrams/gps_tracking_ac.png)

### Inchecken
De stappen die een klant doorloopt wanneer hij/zij de auto terugbrengt en incheckt worden hier geïllustreerd.

![](./diagrams/inchecken_ac.png)

### Inloggen
Dit beschrijft het inlogproces waarbij een klant toegang krijgt tot zijn/haar account.

![](./diagrams/inloggen_ac.png)

### Klant inactief stellen
Het proces waarbij een medewerker een klant inactief kan maken (bijvoorbeeld vanwege wanbetaling) wordt hier beschreven.

![](./diagrams/klant_inactief_stellen_ac.png)

### Klant selecteren
Dit toont hoe een medewerker een specifieke klant kan selecteren voor verdere acties zoals wijzigen of verwijderen.

![](./diagrams/klant_selecteren_ac.png)

### Klant verwijderen
Het proces waarbij een medewerker een klant definitief uit het systeem verwijdert, wordt hier geïllustreerd.

![](./diagrams/klant_verwijderen_ac.png)

### Registreren als klant
Dit diagram beschrijft het volledige registratieproces van een nieuwe klant, van het invoeren van gegevens tot het ontvangen van een bevestigingsmail.

![](./diagrams/registreren_als_klant.png)

### Uitchecken
De stappen die een klant doorloopt om uit te checken na het gebruik van een auto worden hier getoond.

![](./diagrams/uitchecken_ac.png)

### Voertuig zoeken
Dit diagram beschrijft hoe een klant een voertuig zoekt op basis van locatie en beschikbaarheid.

![](./diagrams/voertuig_zoeken_ac.png)

## Design decisions

1. **Monolithic**: Bij het ontwikkelen van het RedCars-systeem is ervoor gekozen om een monolithische architectuur te hanteren. Dit besluit is genomen op basis van de volgende overwegingen:
   
   - **Eenvoud**: Een monolithische architectuur is relatief eenvoudiger te ontwikkelen en te beheren. Alle functionaliteiten en modules van de applicatie zijn ondergebracht in één codebase, wat zorgt voor een gestroomlijnde ontwikkel- en implementatieproces.
   
   - **Uniformiteit**: Doordat alle onderdelen van de applicatie centraal zijn opgeslagen, kunnen updates en wijzigingen consistent en gelijktijdig worden doorgevoerd.
   
   - **Performantie**: In de beginfase van RedCars, waarbij de belasting op het systeem nog relatief laag is, kan een monolithische architectuur voldoende snelle reactietijden bieden zonder de noodzaak van gedistribueerde systemen of microservices.
   
   - **Kostenbesparing**: Met een monolithische aanpak kunnen de initiële ontwikkelings- en onderhoudskosten worden beperkt, aangezien er minder complexiteit is in termen van interacties tussen verschillende services of componenten.
   
   - **Integratie**: Een monolithische structuur biedt een gecentraliseerd systeem voor gegevensopslag en -toegang, wat kan resulteren in minder databasetransacties en een vereenvoudigde gegevensintegriteit.

   Het is belangrijk op te merken dat hoewel een monolithische benadering voordelen biedt in de vroege stadia van de applicatie, toekomstige schaalbaarheid en aanpassingen zorgvuldig moeten worden overwogen naarmate de applicatie en het gebruikersbestand groeien. Er kan in de toekomst een overweging worden gemaakt om over te stappen naar een microservices-architectuur als dat nodig wordt geacht.
