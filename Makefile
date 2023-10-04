srs.pdf: srs.md redcars/uc.svg
	pandoc --template "eisvogel.tex" --listings srs.md -o srs.pdf

redcars/uc.svg: redcars.asta
	[ 1 -eq 2 ]
