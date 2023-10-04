---
title: Software requirements specification
author:
- "Nathan Kolpa"
- "Luke Rieff"
titlepage: true
toc: true
---

# Introductie

> Provide a short description of the software being specified and its purpose, including relevant benefits, objectives, and goals. If a separate description of the product scope is available (e.g. in the PvA), refer to it rather than duplicating its contents here.

## User Classes and Characteristics

> Identify the various user classes (actors) that you anticipate will use this product. User classes may be differentiated based on the subset of product functions used. Describe the pertinent characteristics of each user class. Certain requirements may pertain only to certain user classes.

## Operating Environment

> Describe the environment in which the software will operate, including the hardware platform, operating system and versions, and any other software components or applications with which it must peacefully coexist.

## Design and Implementation Constraints

> Describe any items or issues that will limit the options available to the developers. These might include: hardware (e.g. specific mobile platforms), specific technologies, tools, and databases to be used; interfaces to other applications; programming language required; or communications protocols

## Product Functions

> Summarize the major functions the product must perform or must let the user perform. Details will be provided in Section 3, so only a high level summary is needed here. In most cases, this section will primarily contain a use case diagram and brief use case descriptions

# Domain Model

> Provide a diagram showing important real-situation conceptual classes in the application domain. Do NOT include software classes. Describe each of the conceptual classes in a glossary.

# Usecase Model

![Usecase diagram](redcars/uc.svg)

## Brief Description

### Betalen

**Factureren** Een geregistreerde gebruiker krijgt periodiek een factuur als hij/ zei gekozen heeft voor een
betaald abonnement. De kosten van het factuur worden berekend aan de hand van welk abonnement de klant heeft,
hoeveel killometers er gereden zijn en hoe lang de auto gehuurd is. Sommige abonnementen hebben ook een aantal
vrije killometers, dit wordt dan ook meegenomen.

**abonnement afsluiten** Een geregistreerde gebruiker kiest een abonnement en sluit deze af.

### Huren

**GPS-Tracking** De meest recente locatie van ieder voertuig wordt herhaalijks opgeslagen in het systeem.

**Inchecken** Een gebruiker heeft een voertuig gereserveerd en checkt nu in bij een paal zodat deze gebruikt
kan worden.

**Voertuig reserveren** Een gebruiker is geregistreerd in het systeem en reserveert een voertuig zodat deze
gebruikt kan worden.

**Voertuig zoeken** Een gebruiker die in het systeem is geregistreerd zoekt naar een beschikbaar voertuig
dat in de buurt is.

**Uitchecken** Een gebruiker die ingecheckt heeft wilt nu uitchecken om te stoppen met het gebruiken
van het voertuig.

**Voertuig huren** Een gebruiker die geregistreerd is in het systeem huurt een voertuig om te gebruiken.

### Registreren

**Registreren als klant** De klant geeft zijn/ haar naam, woonplaats en adres op. Ook wordt er een e-mail adres
gevraagd en een bankrekeningnummer. Er wordt een goedkeuring gevraagd voor automatisch incasso, waarna er
een pas wordt verstuurd naar de klant waarmee er ingelogd kan worden.

**Email verifieren** Tijdens de registratie van een klant wordt de email geverifieerd, hierbij krijgt
de klant een e-mail met een verificatiecode die hij/ zei in de browser moet invullen.

**Goedkeuren automatisch incasso** Tijdens de registratie moet de gebruiker toestemming geven voor automatisch
incasso.

### Beheer

**Admin beheer** Het beheren van gegevens in het systeem.

**Voertuig beheer** Het beheren van gegevens van voertuigen.

**Klanten beheer** Het beheren van gegegens van klanten. Hierbij is het mogelijk dat een klant
inactief wordt gemaakt als gevolg van slechte betalingen of het verwaarlozen van voertuigen.

# Requirements

## (F)unctionality

1. Tijdens het registreren moet de naam, het adres en de woonplaats worden opgegeven door de klant.
1. Tijdens het registreren moet een e-mail adres worden opgegeven.
1. Tijdens het registreren moet het e-mail adres worden geverifieerd.
1. Tijdens het registreren moet een bankrekeningnummer worden opgegeven.
1. Tijdens het registreren moet er toestemming worden gevraagd voor automatische incasso.
1. Na het registreren moet een klantenpas worden opgestuurd naar de klant.
1. Na het gebruik van een voertuig moet er automatische incasso plaatsvinden.
1. Een klant moet in kunnen loggen op het systeem met het e-mail adres als gebruikersnaam en het pasnummer als wachtwoord.
1. Klanten moeten inactief kunnen worden gesteld door medewerkers indien er voertuigen gebrekkig achter zijn gelaten.
1. Klanten moeten enkel in de gereserveerde periode de auto kunnen meenemen.

## (R)eliability

1. Het niet mogelijk zijn om een auto te reserveren en in te checken zolang er een betalingsachterstand is.
1. Er moet een betalingsachterstand onstaan wanneer een automatische afschrijving mislukt
1. Het mag niet mogelijk zijn om op hetzelfde tijdstip meerdere malen ingecheckt te zijn.

## (U)sability

1. Klanten moeten snel kunnen zien welke voertuigen er beschikbaar zijn per stad, en waar deze staan.
1. Klanten moeten een auto kunnen reserveren.

## (P)erformance

1. Het systeem moet snel werken, zelfs wanneer er veel klanten tegelijkertijd aan het boeken zijn.

## (S)upportability

1. Medewerkers moeten klantgegevens aan kunnen passen en kunnen bekijken.
1. Medewerkers moeten voertuiggegevens aan kunnen passen en kunnen bekijken.
