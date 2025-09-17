function downloadPDF()
{
    window.print();
}

document.addEventListener('DOMContentLoaded', function()
{
    const downloadBtn = document.getElementById('download-btn');

    downloadBtn.addEventListener('click', downloadPDF);
});