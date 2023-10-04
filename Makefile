srs.pdf: srs.md
	pandoc --template "eisvogel.tex" --listings srs.md -o srs.pdf
