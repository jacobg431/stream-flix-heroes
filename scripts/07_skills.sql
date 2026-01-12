
INSERT INTO Skill (Name, Description)
VALUES
    ('Swordsmanship', 'Expertise in fighting with swords'),
    ('Archery',       'Proficiency in using bows and arrows'),
    ('Magic',         'Ability to cast spells and use magical powers'),
    ('Eagle taxi',    'Ask the great eagles for a quick ride across Middle-earth');


INSERT INTO HeroSkill (HeroId, SkillId)
VALUES
    ((SELECT Id FROM Hero WHERE Name = 'Aragorn'), 
    (SELECT Id FROM Skill WHERE Name = 'Swordsmanship')),

    ((SELECT Id FROM Hero WHERE Name = 'Legolas'),
    (SELECT Id FROM Skill WHERE Name = 'Archery')),

    ((SELECT Id FROM Hero WHERE Name = 'Gandalf'),
    (SELECT Id FROM Skill WHERE Name = 'Magic')),

    ((SELECT Id FROM Hero WHERE Name = 'Gandalf'),
    (SELECT Id FROM Skill WHERE Name = 'Eagle taxi')),

    ((SELECT Id FROM Hero WHERE Name = 'Legolas'),
    (SELECT Id FROM Skill WHERE Name = 'Eagle taxi'));
