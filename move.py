from pathlib import Path
import shutil

contest = 'arc'

root = Path(contest)

for f in Path().glob(contest + '*'):
    if f.is_dir():
        continue
    name, ext = f.name.split('.')
    id_, rank = name.split('_')
    tgt_file = root / id_.strip(contest) / (rank + '.' + ext)
    shutil.move(str(f), str(tgt_file))
