# Multi Parameter Binary Research Tree (MBRT) Library 
## Contents
- ### Tempalte MBRT:
-- Generic Class
-- Single Fully customizable type
-- Customizable Number Of Parameters
-- Automated Parameters Consistency controll
-- Customizablle Compare Function
--- Must Return a Specific Enum described in multiNode.h 
--- Acepted Lambdas and Standard Functions
-- Premade Print Method

- ### Double BRT
-- Not Generic Class (currentrly)
-- Only Int-String parameters (currently)
-- No Inheritance from other Classes

## Roadmap (TODO)
- [] Basic Double BRT: 
-- [x] Add Node
--- [x] Peers Management
-- [x] Print Content
-- [] Get Content (No extraction)
-- [] Remove/Extarct Node
-- [] Search Specific Content 
-- [] Spatial Optimization (maybe not needed)
- [] Template MBRT:
-- [x] Add Node:
--- [x] Peers Management
-- [x] Print Content: 
-- [] Get Content (No extraction)
-- [] Remove/Extarct Node
-- [] Search Specific Content 
-- [] Spatial Optimization for the object
--- Idea: Needed to Reduce Redundancy of internal Vector sizes using native pointers dynamic arrays and only a standard vector for parameters  to keep quality of life for who want to use the library (?)

