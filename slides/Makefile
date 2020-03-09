


all: .out slides.pdf

.out:
	mkdir -p .out

%.pdf: %.tex
	lualatex --interaction=nonstopmode --output-directory=.out $^
	lualatex --interaction=nonstopmode --output-directory=.out $^
	cp .out/$@ $@

.PHONY: .out
.SUFFIXES: 