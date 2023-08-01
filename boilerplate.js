const fs = require('fs');
const folder = process.argv[2] || 'Project';

fs.mkdirSync(folder);
fs.writeFileSync(`${folder}/A.cpp`, '');
fs.writeFileSync(`${folder}/B.cpp`, '')
fs.writeFileSync(`${folder}/C.cpp`, '')
fs.writeFileSync(`${folder}/D.cpp`, '')

