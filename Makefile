srs.pdf: srs.md redcars/uc.svg backgrounds/background1.pdf
	pandoc --template "eisvogel.tex" --listings srs.md -o srs.pdf

redcars/uc.svg: redcars.asta
	[ 1 -eq 2 ]

redcars.zip: srs.pdf
	zip redcars.zip srs.pdf
