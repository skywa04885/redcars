srs.pdf: diagrams/usecase.svg srs.md
	pandoc --template "eisvogel.tex" --listings srs.md -o srs.pdf

diagrams/usecase.svg: diagrams/usecase.txt
	plantuml -tsvg diagrams/usecase.txt
