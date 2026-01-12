
ALTER TABLE Apprentice
ADD CONSTRAINT fk_apprentice_hero
FOREIGN KEY (MentorId)
REFERENCES Hero (Id);
