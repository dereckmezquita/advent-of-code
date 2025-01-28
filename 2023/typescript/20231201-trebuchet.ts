#!/usr/bin/env ts-node
import path from 'path';
import fs from 'fs';

const file: string = path.join(__dirname, '../data/20231201-trebuchet.txt');

function main(): void {
    const lines: string[] = fs.readFileSync(file, 'utf-8').split('\n');
    let sum: number = 0;

    for (const line of lines) {
        if (!line) continue;

        const chars: string[] = line.split('');
        const numbers: string[] = chars.filter((char: string) => {
            return !isNaN(parseInt(char, 10));
        });

        const first: string = numbers[0];
        const last: string = numbers[numbers.length - 1];
        sum += parseInt(first + last);
    }

    console.log(sum);
}

console.time("mainFunction");
main();
console.timeEnd("mainFunction");