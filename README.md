### Skp2Kmz Exporter
This is a [Visual Studio](https://www.visualstudio.com/) project, therefore requires it to build.  
*Note: Due to Sketchup dlls dependencies, currently can only build on Windows 64 bit.*

##### Build:
1. Open the Skp2KmzExporter.sln on Visual Studio.
2. Build Skp2KmzExporter as Windows 64 bit executable.

##### How to use:
On **Windows 64-bit**:
1. Place Sketchup 64-bit's *skp2kmz.dll*, *slapi.dll* and *collada.dll* in the same directory as Skp2KmzExporter.exe.
3. Install or place *mfc100u.dll* in the same directory. 
4. To convert, run following command on Windows command prompt:
    ```sh
    path/to/Skp2KmzExporter.exe path/to/skpFileToBeConverted 
    ```
5. Converted KMZ file should be in the same directory as the SKP file.

On **Linux 64-bit**:
1. Install [Wine](https://www.winehq.org/).
2. Ensure that *skp2kmz.dll*, *slapi.dll*, *collada.dll* and *mfc100u.dll* are in the same directory as Skp2KmzExporter.exe.
3. To convert, run following command on Terminal::
    ```sh
    wine path/to/Skp2KmzExporter.exe path/to/skpFileToBeConverted 
    ```
4. Converted KMZ file should be in the same directory as the SKP file.