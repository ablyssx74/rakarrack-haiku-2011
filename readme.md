### Rakarrack Haiku 2011 is the Haiku port of the latest [rakarrack](https://rakarrack.sourceforge.net/) (0.6.2, 2011 git)

This tree is the Haiku port merged onto upstream's newer code (delayline-based effects, the new Infinity effect, beat-tracking tap tempo, +6dB final limiter, new LFO types, and more). The older 0.6.1-based port lives in `rakarrack-haiku`.

Known gap: the native Haiku GUI (`-H`) has no control panel for the new Infinity effect yet.

Install from a recipe: `haiku/rakarrack-0.6.2.recipe` (set `SOURCE_URI` to a commit/tag, then `haikuporter -S rakarrack`).

### Current Status:
- Pretty much everthing works like effects and even midi with the exception of a few things here there.
-  Midi velocity - not really needed but may look into it eventually. Low priority.
-  Background images.  Not really needed but had to remove them because the files caused a crash in 32bit builds likey due to pixel 4 byte misalignment. May add custom bg images another day. Low priority.
-  ACI - Not really sure even how to use this correctly.  Perhaps requires AUX input for secondary source.  Low priority.
- Midi mapping and other original midi settings - Not really sure how to do this either. Low priority.

Requires: Haiku 64bit (the recipe targets x86_64; 32bit via `haiku.makefile` is untested for this version) 

To see help:  ```make -f haiku.makefile help```

Building From Source:

1. Configure:  ```make -f haiku.makefile config ```

2. Build:  ``` make -f haiku.makefile ``` 

3. Package:  ```make -f haiku.makefile package ```

Steps 1,2,3 all together ``` make -f haiku.makefile release ```

To clean: ``` make -f haiku.makefile clean``` 

<br>
GTK Theme<br>
<img width="510" height="460" alt="screenshot" src="https://github.com/user-attachments/assets/1c5eb8c9-33a9-4d51-bb37-7387207e271f" /><br>
Plastic Theme<br>
<img width="510" height="460" alt="Image" src="https://github.com/user-attachments/assets/04c3984a-30de-4aba-96fb-82ead7a4def3" /><br>
From Terminal rakarrack -H ( Haiku mode )<br>
<img width="510" height="460" alt="Image" src="https://github.com/user-attachments/assets/ccd84f1f-571b-4689-a1c8-f4b649d4cdee" />
