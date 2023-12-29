using System;
using System.IO;
using System.Linq;
using System.Collections.Generic;

namespace Day5 {
		class Program {

				public static long MapRange(long x, long inMin, long inMax, long outMin, long outMax) {
						return (x - inMin) * (outMax - outMin) / (inMax - inMin) + outMin;
				}

				public static long[] GetCorresponding(long[] seeds, long[][] rules) {

						long[] res = seeds;
						long i = 0;

						foreach (var seed in seeds) {
								foreach (var rule in rules) {
										if (seed >= rule[1] && seed < (rule[1] + rule[2])) {
												res[i] = MapRange(seed, rule[1], rule[1] + rule[2],
																        rule[0], rule[0] + rule[2]);
										}
								}
								i = i + 1;
						}

						return res;
				}

				public static long Solve1(String filepath) {

						var contents = File.ReadAllText(filepath);
						var parts = contents.Split("\n\n");

						var seeds = Array.ConvertAll(
										 parts[0].Split(" ")[1..], 
								 x => long.Parse(x)).ToArray();

						foreach (var x in parts) {
								var t = x.Split("\n", StringSplitOptions.RemoveEmptyEntries)[1..]
										 .Select(x => Array.ConvertAll(x.Split(" "), x => long.Parse(x))).ToArray();

								seeds = GetCorresponding(seeds, t);
						}

						return seeds.Min();
				}

				public static string Solve2(String filepath) {

						return "Out of Memory LUL";
				}

				public static void Main(string[] args) {
						var filepath = @"./input.txt";

						Console.WriteLine(Solve1(filepath));
						Console.WriteLine(Solve2(filepath));
				}
		}
}
