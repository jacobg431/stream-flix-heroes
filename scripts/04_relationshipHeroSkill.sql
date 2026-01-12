
CREATE TABLE HeroSkill (
    HeroId  INT NOT NULL,
    SkillId INT NOT NULL,

    CONSTRAINT pk_hero_skill
        PRIMARY KEY (HeroId, SkillId),
    
    CONSTRAINT fk_hero_skill_hero
        FOREIGN KEY (HeroId)
        REFERENCES Hero (Id)
        ON DELETE CASCADE,

    CONSTRAINT fk_hero_skill_skill
        FOREIGN KEY (SkillId)
        REFERENCES Skill (Id)
        ON DELETE CASCADE
);
