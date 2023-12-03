const fs = require('fs')

function count(array) {
	let red = [], green = [], blue = []
	for (let i = 0; i < array.length; i++) {
		switch (array[i]) {
			case 'blue':
				blue.push(parseInt(array[i - 1]))
				break
			case 'green':
				green.push(parseInt(array[i - 1]))
				break
			case 'red':
				red.push(parseInt(array[i - 1]))
				break
		}
	}
	return {red: Math.max(...red), green: Math.max(...green), blue: Math.max(...blue)}
}

function parseInput(str) {
 	return str.split("\n")
  		      .map(x => x.split(":")).slice(0, -1)
 			  .map(x => [
 				  	parseInt(x[0].split(" ").pop()), 
 					count(x[1].replace(/[,;]/g, "").split(" ").filter(x => x.trim() != ""))
 			  		])
}

function solve1(filepath) {
	const input = fs.readFileSync(filepath).toString()
	let parsed = parseInput(input)

	let r = 0
	parsed.forEach(x => {
		if (x[1].red <= 12 && x[1].green <= 13 && x[1].blue <= 14) {
				r = r + x[0]
		}
	})
	return r
}

function solve2(filepath) {
	const input = fs.readFileSync(filepath).toString()
	let parsed = parseInput(input)

	let r = 0
	parsed.forEach(x => {
		r = r + (x[1].red * x[1].green * x[1].blue)
	})
	return r
}

function main() {
	let filepath = "./input.txt"
		
	console.log(solve1(filepath))
	console.log(solve2(filepath))
}

main()
