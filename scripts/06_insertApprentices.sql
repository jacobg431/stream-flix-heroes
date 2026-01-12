

INSERT INTO Apprentice (Name, MentorId)
VALUES
    ('Frodo',   (SELECT Id FROM Hero WHERE Name = 'Aragorn')),
    ('Samwise', (SELECT Id FROM Hero WHERE Name = 'Aragorn')),
    ('Merry',   (SELECT Id FROM Hero WHERE Name = 'Legolas')),
    ('Pippin',  (SELECT Id FROM Hero WHERE Name = 'Legolas')),
    ('Saruman', (SELECT Id FROM Hero WHERE Name = 'Gandalf'));

