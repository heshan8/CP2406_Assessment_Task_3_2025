# Clean up old simulation files so the simulation runs form scrartch every time.

#Status messeges for clarity
Write-Host "`nCleaning up previous run...`n"

# Remove the 'images' directory if it exists
if (Test-Path "images") {
    Remove-Item -Recurse -Force "images"
    Write-Host "Removed old 'images' folder."
}

# Create the 'images' directory
New-Item -ItemType Directory -Path "images" | Out-Null
Write-Host "Created new 'images' folder."

# Remove the 'result.mp4' file if it exists
if (Test-Path "result.mp4") {
    Remove-Item -Force "result.mp4"
    Write-Host "Removed old 'results.mp4'."
}

Write-Host "`nCleanup complete. Running Simulation...`n"