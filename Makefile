srs.pdf: srs.md redcars/uc.svg backgrounds/background1.pdf diagrams/domein.svg
	pandoc --template "eisvogel.tex" --listings srs.md -o srs.pdf

sdd.pdf: sdd.md backgrounds/background1.pdf
	pandoc --template "eisvogel.tex" --listings sdd.md -o sdd.pdf

redcars.zip: srs.pdf
	zip redcars.zip srs.pdf
