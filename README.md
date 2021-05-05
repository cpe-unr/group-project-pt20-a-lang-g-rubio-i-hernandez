# CS 202 Semester Project Template

# Project Description
In this project, you are going to create an audio file management system. The system will store its information in a CSV file that can easily be imported into any spreadsheet program. 
# Members
Gustavo
Antonio
Israel

# Areas of code and responsibilities
Israel:
Given a directory of audio files in wav format, the system will read in each file one at a time and extract all the technical information (sample rate, etc.) as well as any metadata included in the file. The object holding the information should be added to an appropriate data structure, and the sound file data (sound buffer, etc) should be deleted from the heap (NOT DISK!). 
The data from each file is to be stored using a class that is designed for the type of file. The files may be mono or stereo and may be 8 or 16 bit samples.

Antonio:
When all the files are read and processed, the user can choose to modify the metadata of any file. When the modification is complete, the file must be saved with the new metadata. The modifications should override any current metadata, or create the metadata if it didn’t exist previously. 

Gustavo:
The user may choose to process a file by choosing one or more processors. Processors should be applied in sequence. The provided processors should include normalization, noise gating, and echo.

Antonio:
After processing, the user should be prompted for a file name and if valid, a new file is created with the processed audio. The user is not allowed to save the file under the same name as any of the existing files.

Gustavo:
If the user chooses to do so, a CSV file can be exported listing all the files, their technical information (sample rates, etc.), and the file metadata. If no metadata exists, the phrase “No metadata present” should be included in the description for that file. 

# Design:
https://app.creately.com/diagram/nHs4IurksLH/view

# Challenges
Reading/writing the metadata was certainly the most prominent of challenges.
Working with templates and inheritance properly at the same time came as a close second.
